package com.zeroone.star.contractmanagement.entity;

import com.baomidou.mybatisplus.annotation.*;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;
import java.time.LocalDateTime;

/**
 * <p>
 * 
 * </p>
 *
 * @author kunge
 * @since 2025-05-28
 */
@Getter
@Setter
@TableName("s_store")
public class SStore implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 商店ID
     */
    @TableId(value = "store_id",type = IdType.ASSIGN_ID)
    private String storeId;

    /**
     * 业务ID
     */
    private String bId;

    /**
     * 用户ID
     */
    private String userId;

    /**
     * 店铺名称
     */
    private String name;

    /**
     * 店铺地址
     */
    private String address;

    /**
     * 电话
     */
    private String tel;

    private String storeTypeCd;

    /**
     * 地标，如王府井北60米
     */
    private String nearbyLandmarks;

    /**
     * 地区 x坐标
     */
    private String mapX;

    /**
     * 地区 y坐标
     */
    private String mapY;

    /**
     * 创建时间
     */
    @TableField(fill = FieldFill.INSERT)
    private LocalDateTime createTime;

    /**
     * 数据状态，详细参考c_status表，S 保存，0, 在用 1失效
     */
    @TableLogic(value = "0", delval = "1")
    private String statusCd;

    /**
     * 48001 商户正常状态 48002 限制商户登录
     */
    private String state;


}
