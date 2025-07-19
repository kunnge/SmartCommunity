package com.zeroone.star.systemmanage.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Data;

import java.math.BigDecimal;
import java.time.LocalDateTime;

@Data
@TableName("pay_fee")
public class PayFeeDO {
    /**
    * 费用ID
    */
    private String feeId;

    /**
     * 业务ID
     */
    private String bId;

    /**
     * 费用类型，物业费，停车费
     */
    private String feeTypeCd;

    /**
     * 小区ID
     */
    private String communityId;

    /**
     * 付款方ID
     */
    private String payerObjId;

    /**
     * 收款方ID
     */
    private String incomeObjId;

    /**
     * 开始时间
     */
    private LocalDateTime startTime;

    /**
     * 结束时间
     */
    private LocalDateTime endTime;

    /**
     * 总金额，如物业费，停车费等没有总金额的，填写为-1.00
     */
    private BigDecimal amount;

    /**
     * 创建用户ID
     */
    private String userId;

    /**
     * 创建时间
     */
    private LocalDateTime createTime;

    /**
     * 数据状态，详细参考c_status表，S 保存，0, 在用 1失效
     */
    private String statusCd;

    /**
     * 费用标识 1003006 为周期性费用 2006012 为一次性费用
     */
    private String feeFlag;

    /**
     * 状态 2007001收费未开始 2008001 收费中状态 2009001 收费结束
     */
    private String state;

    /**
     * 费用项ID
     */
    private String configId;

    /**
     * 付费对象类型 3333 房屋 6666 是车位
     */
    private String payerObjType;

    /**
     * 批次ID
     */
    private String batchId;
}
