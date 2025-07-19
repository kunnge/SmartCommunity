//package com.zeroone.star.gateway.config;
//
//import com.alibaba.cloud.commons.lang.StringUtils;
//import com.zeroone.star.project.components.jwt.JwtComponent;
//import com.zeroone.star.project.components.jwt.exception.JwtExpiredException;
//import com.zeroone.star.project.components.user.UserHolder;
//import com.zeroone.star.project.vo.JsonVO;
//import lombok.SneakyThrows;
//import lombok.extern.slf4j.Slf4j;
//import org.apache.ibatis.logging.slf4j.Slf4jImpl;
//import org.springframework.cloud.gateway.filter.GatewayFilterChain;
//import org.springframework.cloud.gateway.filter.GlobalFilter;
//import org.springframework.context.annotation.Lazy;
//import org.springframework.core.Ordered;
//import org.springframework.core.io.buffer.DataBuffer;
//import org.springframework.http.HttpHeaders;
//import org.springframework.http.HttpStatus;
//import org.springframework.http.server.reactive.ServerHttpResponse;
//import org.springframework.stereotype.Component;
//import org.springframework.web.server.ServerWebExchange;
//import reactor.core.publisher.Mono;
//
//import javax.annotation.Resource;
//import java.nio.charset.StandardCharsets;
//
///*
// *描述 ：全局过滤器
// *Author:28768
// */
//@Component
//public class GlobalFilterConfig implements GlobalFilter, Ordered {
//
////    @Resource
////    @Lazy
////    private UserHolder userHolder;
//
////    @Resource
////    private JwtComponent jwtComponent;
//
//
//    @Override
//    public Mono<Void> filter(ServerWebExchange exchange, GatewayFilterChain chain) {
//        // 在此处进行身份验证和权限检查逻辑
//        // 如果身份验证失败或者权限不足，则直接返回未授权的响应
//        // 否则，继续执行后续的过滤器和路由处理逻辑
//        HttpHeaders headers = exchange.getRequest().getHeaders();
//        String token = headers.getFirst("Authorization");
//        //判断token是否为空
//        if(StringUtils.isEmpty(token)){
//            //设置响应值
//           return unauthorizedResponse(exchange,"token为空");
//        }
//        JwtComponent jwtComponent = new JwtComponent();
//        //校验token
//        try {
//            System.out.println(jwtComponent.defaultRsaVerify(token));
//        } catch (Exception e) {
////            throw new JwtExpiredException("token过期或者无效");
//            return unauthorizedResponse(exchange,"token过期或者无效");
//        }
//
////        if (token == null || !token.equals("valid_token")) {
////            exchange.getResponse().setStatusCode(HttpStatus.UNAUTHORIZED);
////            return exchange.getResponse().setComplete();
////        }
//        return chain.filter(exchange);
//    }
//    private Mono<Void> unauthorizedResponse(ServerWebExchange exchange, String message) {
//        ServerHttpResponse response = exchange.getResponse();
//
//        response.setStatusCode(HttpStatus.UNAUTHORIZED);
//        response.getHeaders().add("Content-Type", "application/json;charset=UTF-8");
//
//        String body = String.format("{\"code\":%d,\"msg\":\"%s\"}",HttpStatus.UNAUTHORIZED.value(),message);
//        DataBuffer buffer = response.bufferFactory().wrap(body.getBytes(StandardCharsets.UTF_8));
//
//        return response.writeWith(Mono.just(buffer));
//    }
//
//    @Override
//    public int getOrder() {
//        return -1; // 设置过滤器的执行顺序，负数代表早于默认的过滤器执行
//    }
//}
