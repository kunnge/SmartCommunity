package com.zeroone.star.project.dto.j7.parkmanage.ownervehicle;

import com.fasterxml.jackson.annotation.JsonFormat;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.NotBlank;
import javax.validation.constraints.Size;
import java.time.LocalDate;

@Data
@ApiModel("添加车辆模型")
public class AddCarDTO {
    @ApiModelProperty(value = "车牌号", example = "渝A12112", required = true)
    @NotBlank(message = "车牌号不能为空")
    @Size(max = 12, message = "车牌号不正确")
    private String carNum;

    @ApiModelProperty(value = "车类型 9901 家用小汽车，9902 客车，9903 货车，9904 电动车，9905 三轮车，9906 信用期车辆", example = "9901", required = true)
    @NotBlank(message = "车类型不能为空")
    private String carType;

    @ApiModelProperty(value = "车牌类型 H 月租车，S 出售车，I 内部车，NM 免费车", example = "H", required = true)
    @NotBlank(message = "车牌类型不能为空")
    private String leaseType;

    @ApiModelProperty(value = "起租时间", example = "2025-05-20")
    @JsonFormat(pattern = "yyyy-MM-dd")
    private LocalDate startTime;

    @ApiModelProperty(value = "业主id", example = "772024022641420195", required = true)
    @NotBlank(message = "业主不能为空")
    private String ownerId;

    @ApiModelProperty(value = "备注", example = "测试")
    @Size(max = 200, message = "备注长度不能超过200字")
    private String remark;

    @ApiModelProperty(value = "汽车品牌", example = "小米su7")
    @Size(max = 50, message = "汽车品牌超出限制")
    private String carBrand;

    @ApiModelProperty(value = "颜色", example = "珍珠白")
    @Size(max = 12, message = "颜色长度超出限制")
    private String carColor;

    @ApiModelProperty(value = "结租时间", example = "2050-01-01")
    @JsonFormat(pattern = "yyyy-MM-dd")
    private LocalDate endTime;

    @ApiModelProperty(value = "车位id", example = "792025052097620012", required = true)
    @NotBlank(message = "车位不能为空")
    private String psId;

    @ApiModelProperty(value = "社区id", example = "2024022643710121", required = true)
    private String communityId;
}
