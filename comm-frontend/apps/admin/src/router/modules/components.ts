import { $t } from "@/plugins/i18n";
import { RouterOrderEnums } from "@/router/enums";

// import { components } from "@/router/enums";

export default {
	path: "/components",
	redirect: "/components/dialog",
	meta: {
		icon: "ep/menu",
		title: $t("common.menus.pureComponents"),
		rank: RouterOrderEnums.components,
	},
	children: [
		{
			path: "/components/dialog",
			name: "DialogPage",
			component: () => import("@/views/components/dialog/index.vue"),
			meta: {
				title: $t("common.menus.pureDialog"),
			},
		},
		{
			path: "/components/drawer",
			name: "DrawerPage",
			component: () => import("@/views/components/drawer/index.vue"),
			meta: {
				title: $t("common.menus.pureDrawer"),
			},
		},
		{
			path: "/components/message",
			name: "Message",
			component: () => import("@/views/components/message.vue"),
			meta: {
				title: $t("common.menus.pureMessage"),
			},
		},
		{
			path: "/components/upload",
			name: "PureUpload",
			component: () => import("@/views/components/upload/index.vue"),
			meta: {
				title: $t("common.menus.pureUpload"),
			},
		},
		{
			path: "/components/check-card",
			name: "CheckCard",
			component: () => import("@/views/components/check-card.vue"),
			meta: {
				title: $t("common.menus.pureCheckCard"),
			},
		},
		{
			path: "/components/date-picker",
			name: "DatePicker",
			component: () => import("@/views/components/date-picker.vue"),
			meta: {
				title: $t("common.menus.pureDatePicker"),
			},
		},
		{
			path: "/components/datetime-picker",
			name: "DateTimePicker",
			component: () => import("@/views/components/datetime-picker.vue"),
			meta: {
				title: $t("common.menus.pureDateTimePicker"),
			},
		},
		{
			path: "/components/time-picker",
			name: "TimePicker",
			component: () => import("@/views/components/time-picker.vue"),
			meta: {
				title: $t("common.menus.pureTimePicker"),
			},
		},
		{
			path: "/components/icon-select",
			name: "IconSelect",
			component: () => import("@/views/components/icon-select.vue"),
			meta: {
				title: $t("common.menus.pureIconSelect"),
			},
		},
		{
			path: "/components/animatecss",
			name: "AnimateCss",
			component: () => import("@/views/components/animatecss.vue"),
			meta: {
				title: $t("common.menus.pureAnimatecss"),
			},
		},
		{
			path: "/components/cropping",
			name: "Cropping",
			component: () => import("@/views/components/cropping/index.vue"),
			meta: {
				title: $t("common.menus.pureCropping"),
			},
		},
		{
			path: "/components/segmented",
			name: "Segmented",
			component: () => import("@/views/components/segmented.vue"),
			meta: {
				title: $t("common.menus.pureSegmented"),
			},
		},
		{
			path: "/components/text",
			name: "PureText",
			component: () => import("@/views/components/text.vue"),
			meta: {
				title: $t("common.menus.pureText"),
			},
		},
		{
			path: "/components/slider",
			name: "PureSlider",
			component: () => import("@/views/components/slider/index.vue"),
			meta: {
				title: $t("common.menus.pureSlider"),
				extraIcon: "IF-pure-iconfont-new svg",
			},
		},
		{
			path: "/components/el-button",
			name: "PureButton",
			component: () => import("@/views/components/el-button.vue"),
			meta: {
				title: $t("common.menus.pureElButton"),
			},
		},
		{
			path: "/components/check-button",
			name: "CheckButton",
			component: () => import("@/views/components/check-button.vue"),
			meta: {
				title: $t("common.menus.pureCheckButton"),
			},
		},
		{
			path: "/components/button",
			name: "ButtonPage",
			component: () => import("@/views/components/button.vue"),
			meta: {
				title: $t("common.menus.pureButton"),
			},
		},
		{
			path: "/components/progress",
			name: "PureProgress",
			component: () => import("@/views/components/progress.vue"),
			meta: {
				title: $t("common.menus.pureProgress"),
			},
		},
		{
			path: "/components/tag",
			name: "PureTag",
			component: () => import("@/views/components/tag.vue"),
			meta: {
				title: $t("common.menus.pureTag"),
			},
		},
		{
			path: "/components/statistic",
			name: "Statistic",
			component: () => import("@/views/components/statistic.vue"),
			meta: {
				title: $t("common.menus.pureStatistic"),
			},
		},
		{
			path: "/components/collapse",
			name: "Collapse",
			component: () => import("@/views/components/collapse.vue"),
			meta: {
				title: $t("common.menus.pureCollapse"),
			},
		},
		{
			path: "/components/cascader",
			name: "Cascader",
			component: () => import("@/views/components/cascader.vue"),
			meta: {
				title: $t("common.menus.pureCascader"),
			},
		},
		{
			path: "/components/color-picker",
			name: "ColorPicker",
			component: () => import("@/views/components/color-picker.vue"),
			meta: {
				title: $t("common.menus.pureColorPicker"),
			},
		},
		{
			path: "/components/selector",
			name: "Selector",
			component: () => import("@/views/components/selector.vue"),
			meta: {
				title: $t("common.menus.pureSelector"),
			},
		},
		{
			path: "/components/waterfall",
			name: "Waterfall",
			component: () => import("@/views/components/waterfall/index.vue"),
			meta: {
				title: $t("common.menus.pureWaterfall"),
			},
		},
		{
			path: "/components/split-pane",
			name: "SplitPane",
			component: () => import("@/views/components/split-pane.vue"),
			meta: {
				title: $t("common.menus.pureSplitPane"),
			},
		},
		{
			path: "/components/swiper",
			name: "Swiper",
			component: () => import("@/views/components/swiper.vue"),
			meta: {
				title: $t("common.menus.pureSwiper"),
			},
		},
		{
			path: "/components/timeline",
			name: "TimeLine",
			component: () => import("@/views/components/timeline.vue"),
			meta: {
				title: $t("common.menus.pureTimeline"),
			},
		},
		{
			path: "/components/count-to",
			name: "CountTo",
			component: () => import("@/views/components/count-to.vue"),
			meta: {
				title: $t("common.menus.pureCountTo"),
			},
		},
		{
			path: "/components/contextmenu",
			name: "ContextMenu",
			component: () => import("@/views/components/contextmenu/index.vue"),
			meta: {
				title: $t("common.menus.pureContextmenu"),
			},
		},
		{
			path: "/components/json-editor",
			name: "JsonEditor",
			component: () => import("@/views/components/json-editor.vue"),
			meta: {
				title: $t("common.menus.pureJsonEditor"),
			},
		},
		{
			path: "/components/seamless-scroll",
			name: "SeamlessScroll",
			component: () => import("@/views/components/seamless-scroll.vue"),
			meta: {
				title: $t("common.menus.pureSeamless"),
			},
		},
		{
			path: "/components/virtual-list",
			name: "VirtualList",
			component: () => import("@/views/components/virtual-list/index.vue"),
			meta: {
				title: $t("common.menus.pureVirtualList"),
			},
		},
	],
} satisfies RouteConfigsTable;
