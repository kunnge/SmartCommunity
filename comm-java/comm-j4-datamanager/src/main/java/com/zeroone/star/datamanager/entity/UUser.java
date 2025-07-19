package com.zeroone.star.datamanager.entity;

import com.baomidou.mybatisplus.annotation.FieldFill;
import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.time.LocalDateTime;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 
 * </p>
 *
 * @author zhangdashuai
 * @since 2025-05-21
 */
@Getter
@Setter
@TableName("u_user")
public class UUser implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * id
     */
    @TableId(value = "id", type = IdType.AUTO)
    private Integer id;

    /**
     * 用户ID
     */
    private String userId;

    /**
     * 名称
     */
    private String name;

    /**
     * 邮箱地址
     */
    private String email;

    /**
     * 现居住地址
     */
    private String address;

    /**
     * 用户密码，加密过后
     */
    private String password;

    /**
     * 用户地区，编码详见 u_location
     */
    private String locationCd;

    /**
     * 用户年龄
     */
    private Integer age;

    /**
     * 性别，0表示男孩 1表示女孩
     */
    private String sex;

    private String tel;

    /**
     * 用户级别,关联user_level
     */
    private String levelCd;

    /**
     * 业务ID
     */
    private String bId;

    /**
     * 创建时间
     */
    @TableField(fill = FieldFill.INSERT)
    private LocalDateTime createTime;

    /**
     * 数据状态，详细参考c_status表，S 保存，0, 在用 1失效
     */
    private String statusCd;

    /**
     * 评分
     */
    private String score;


}
