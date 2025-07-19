package com.zeroone.star.project.components.user;

import lombok.Builder;
import lombok.Data;

import java.util.List;

/**
 * <p>
 * 描述：用户数据
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author 阿伟学长
 * @version 1.0.0
 */
@Data
@Builder
public class UserDTO {

    /**
     * 用户编号 已根据数据库设计情况修正ID的数据类型
     */
    private String id;

    /**
     * 用户名称
     */
    private String username;

    /**
     * 是否启用
     */
    private Byte isEnabled;

    /**
     * 用户拥有角色列表
     */
    private List<String> roles;

    /**
     * 用户关联的所有商店ID列表（从JWT中获取）
     */
    private List<String> storeIds;

}
