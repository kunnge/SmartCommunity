package com.zeroone.star.housemgt.config;

import com.zeroone.star.project.config.swagger.SwaggerCore;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import springfox.documentation.spring.web.plugins.Docket;
import springfox.documentation.swagger2.annotations.EnableSwagger2WebMvc;

@Configuration
@EnableSwagger2WebMvc
public class SwaggerConfig {
    @Bean
    Docket sampleApi(){
        return SwaggerCore.defaultDocketBuilder("房产管理业委会业务模块", "com.zeroone.star.housemgt.controller", "housemanagement");
    }
}
