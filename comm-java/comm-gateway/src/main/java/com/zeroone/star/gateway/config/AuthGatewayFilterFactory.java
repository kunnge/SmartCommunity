//package com.zeroone.star.gateway.config;
//
//import com.alibaba.cloud.commons.lang.StringUtils;
//import com.zeroone.star.project.components.jwt.JwtComponent;
//import org.springframework.cloud.gateway.filter.GatewayFilter;
//import org.springframework.cloud.gateway.filter.factory.AbstractGatewayFilterFactory;
//
//import org.springframework.core.io.buffer.DataBuffer;
//import org.springframework.http.HttpStatus;
//import org.springframework.http.MediaType;
//import org.springframework.http.server.reactive.ServerHttpRequest;
//import org.springframework.http.server.reactive.ServerHttpResponse;
//import org.springframework.stereotype.Component;
//import org.springframework.web.server.ServerWebExchange;
//import reactor.core.publisher.Mono;
//
//import java.nio.charset.StandardCharsets;
//
//
///*
// *描述 ：
// *Author:28768
// */
//
//@Component
//public class AuthGatewayFilterFactory extends AbstractGatewayFilterFactory<AuthGatewayFilterFactory.Config> {
//
//    public AuthGatewayFilterFactory() {
//        super(Config.class);
//    }
//
//    @Override
//    public GatewayFilter apply(Config config) {
//        return (exchange, chain) -> {
//            ServerHttpRequest request = exchange.getRequest();
//            String token = getTokenFromRequest(request);
//
//            // 假设我们有一个JwtService类来处理验证逻辑
//            JwtComponent jwtComponent = new JwtComponent();
//            if (!StringUtils.isEmpty( token)) {
//                try {
//                    jwtComponent.defaultRsaVerify(token);
//                } catch (Exception e) {
//                    return unauthorizedResponse(exchange);
//                }
//                return chain.filter(exchange);
//            } else {
//
//                return unauthorizedResponse(exchange);
//            }
//        };
//    }
//
//    private Mono<Void> unauthorizedResponse(ServerWebExchange exchange) {
//        ServerHttpResponse response = exchange.getResponse();
//        response.setStatusCode(HttpStatus.UNAUTHORIZED);
//        response.getHeaders().setContentType(MediaType.APPLICATION_JSON);
//
//        String body = "{\"code\":401,\"msg\":\"Unauthorized\"}";
//        DataBuffer buffer = response.bufferFactory().wrap(body.getBytes(StandardCharsets.UTF_8));
//        System.out.println("返回401");
//        // writeWith() 会写入 body 并结束响应
//        return response.writeWith(Mono.just(buffer));
//    }
//
//    private String getTokenFromRequest(ServerHttpRequest request) {
//        // 从请求头中获取JWT令牌
//        return request.getHeaders().getFirst("Authorization").replace("Bearer ", "");
//    }
//
//    // 配置类可选，根据需要添加配置参数
//    public static class Config {
//        // 示例配置项，实际应用可能不需要
//        // private String headerName;
//        // ...
//    }
//}
