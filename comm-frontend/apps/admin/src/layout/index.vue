<script setup lang="ts">
import "animate.css";
// 引入 src/components/ReIcon/src/offlineIcon.ts 文件中所有使用addIcon添加过的本地图标
import "@/components/ReIcon/src/offlineIcon";
import { setType } from "./types";
import { useI18n } from "vue-i18n";
import { useLayout } from "./hooks/useLayout";
import { useAppStoreHook } from "@/store/modules/app";
import { useSettingStoreHook } from "@/store/modules/settings";
import { useDataThemeChange } from "@/layout/hooks/useDataThemeChange";
import { h, ref, reactive, computed, onMounted, onBeforeMount, defineComponent } from "vue";
import { useDark, useGlobal, deviceDetection, useResizeObserver } from "@pureadmin/utils";

import LayTag from "./components/lay-tag/index.vue";
import LayNavbar from "./components/lay-navbar/index.vue";
import LayContent from "./components/lay-content/index.vue";
import LaySetting from "./components/lay-setting/index.vue";
import NavVertical from "./components/lay-sidebar/NavVertical.vue";
import NavHorizontal from "./components/lay-sidebar/NavHorizontal.vue";
import BackTopIcon from "@/assets/svg/back_top.svg?component";

const { t } = useI18n();
const appWrapperRef = ref();
const { isDark } = useDark();
const { layout } = useLayout();
const isMobile = deviceDetection();
const pureSetting = useSettingStoreHook();
const { $storage } = useGlobal<GlobalPropertiesApi>();

const set: setType = reactive({
	sidebar: computed(() => {
		return useAppStoreHook().sidebar;
	}),

	device: computed(() => {
		return useAppStoreHook().device;
	}),

	fixedHeader: computed(() => {
		return pureSetting.fixedHeader;
	}),

	classes: computed(() => {
		return {
			hideSidebar: !set.sidebar.opened,
			openSidebar: set.sidebar.opened,
			withoutAnimation: set.sidebar.withoutAnimation,
			mobile: set.device === "mobile",
		};
	}),

	hideTabs: computed(() => {
		return $storage?.configure.hideTabs;
	}),
});

function setTheme(layoutModel: string) {
	window.document.body.setAttribute("layout", layoutModel);
	$storage.layout = {
		layout: `${layoutModel}`,
		theme: $storage.layout?.theme,
		darkMode: $storage.layout?.darkMode,
		sidebarStatus: $storage.layout?.sidebarStatus,
		epThemeColor: $storage.layout?.epThemeColor,
		themeColor: $storage.layout?.themeColor,
		overallStyle: $storage.layout?.overallStyle,
	};
}

function toggle(device: string, bool: boolean) {
	useAppStoreHook().toggleDevice(device);
	useAppStoreHook().toggleSideBar(bool, "resize");
}

// 判断是否可自动关闭菜单栏
let isAutoCloseSidebar = true;

useResizeObserver(appWrapperRef, (entries) => {
	if (isMobile) return;
	const entry = entries[0];
	const [{ inlineSize: width, blockSize: height }] = entry.borderBoxSize;
	useAppStoreHook().setViewportSize({ width, height });
	width <= 760 ? setTheme("vertical") : setTheme(useAppStoreHook().layout);
	/** width app-wrapper类容器宽度
	 * 0 < width <= 760 隐藏侧边栏
	 * 760 < width <= 990 折叠侧边栏
	 * width > 990 展开侧边栏
	 */
	if (width > 0 && width <= 760) {
		toggle("mobile", false);
		isAutoCloseSidebar = true;
	} else if (width > 760 && width <= 990) {
		if (isAutoCloseSidebar) {
			toggle("desktop", false);
			isAutoCloseSidebar = false;
		}
	} else if (width > 990 && !set.sidebar.isClickCollapse) {
		toggle("desktop", true);
		isAutoCloseSidebar = true;
	} else {
		toggle("desktop", false);
		isAutoCloseSidebar = false;
	}
});

onMounted(() => {
	if (isMobile) {
		toggle("mobile", false);
	}
});

onBeforeMount(() => {
	useDataThemeChange().dataThemeChange($storage.layout?.overallStyle);
});

const LayHeader = defineComponent({
	name: "LayHeader",
	render() {
		return h(
			"div",
			{
				class: { "fixed-header": set.fixedHeader },
				style: [
					set.hideTabs && layout.value.includes("horizontal")
						? isDark.value
							? "box-shadow: 0 1px 4px #0d0d0d"
							: "box-shadow: 0 1px 4px rgba(0, 21, 41, 0.08)"
						: "",
				],
			},
			{
				default: () => [
					!pureSetting.hiddenSideBar && (layout.value.includes("vertical") || layout.value.includes("mix"))
						? h(LayNavbar)
						: null,
					!pureSetting.hiddenSideBar && layout.value.includes("horizontal") ? h(NavHorizontal) : null,
					h(LayTag),
				],
			},
		);
	},
});
</script>

<template>
	<div ref="appWrapperRef" :class="['app-wrapper', set.classes]">
		<div
			v-show="set.device === 'mobile' && set.sidebar.opened && layout.includes('vertical')"
			class="app-mask"
			@click="useAppStoreHook().toggleSideBar()"
		/>
		<NavVertical v-show="!pureSetting.hiddenSideBar && (layout.includes('vertical') || layout.includes('mix'))" />
		<div :class="['main-container', pureSetting.hiddenSideBar ? 'main-hidden' : '']">
			<div v-if="set.fixedHeader">
				<LayHeader />
				<!-- 主体内容 -->
				<LayContent :fixed-header="set.fixedHeader" />
			</div>
			<el-scrollbar v-else>
				<el-backtop :title="t('common.buttons.pureBackTop')" target=".main-container .el-scrollbar__wrap">
					<BackTopIcon />
				</el-backtop>
				<LayHeader />
				<!-- 主体内容 -->
				<LayContent :fixed-header="set.fixedHeader" />
			</el-scrollbar>
		</div>
		<!-- 系统设置 -->
		<LaySetting />
	</div>
</template>

<style lang="scss" scoped>
.app-wrapper {
	position: relative;
	width: 100%;
	height: 100%;

	&::after {
		clear: both;
		display: table;
		content: "";
	}

	&.mobile.openSidebar {
		position: fixed;
		top: 0;
	}
}

.app-mask {
	position: absolute;
	top: 0;
	z-index: 2001;
	width: 100%;
	height: 100%;
	background: #000;
	opacity: 0.3;
}

.re-screen {
	margin-top: 12px;
}
</style>
