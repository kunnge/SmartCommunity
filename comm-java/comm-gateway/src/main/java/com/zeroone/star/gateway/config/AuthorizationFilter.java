//package com.zeroone.star.gateway.config;
//
///*
// *描述 ：
// *Author:28768
// */
//
//import com.alibaba.cloud.commons.lang.StringUtils;
//import com.zeroone.star.project.components.jwt.JwtComponent;
//import org.springframework.cloud.gateway.filter.GatewayFilter;
//import org.springframework.cloud.gateway.filter.GatewayFilterChain;
//import org.springframework.core.Ordered;
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
//@Component
//public class AuthorizationFilter implements GatewayFilter, Ordered {
//
// private String getTokenFromRequest(ServerHttpRequest request) {
//  // 获取请求中的Token，比如从Authorization Header中提取Bearer Token
//  return request.getHeaders().getFirst("Authorization").replace("Bearer ", "");
// }
//
// @Override
// public int getOrder() {
//  // 设置过滤器执行顺序，可以根据需求调整
//  return -1;
// }
//
// @Override
// public Mono<Void> filter(ServerWebExchange exchange, GatewayFilterChain chain) {
//  String token = getTokenFromRequest(exchange.getRequest());
//  ServerHttpResponse response = exchange.getResponse();
//  // 验证Token有效性（这里只是一个示例，实际验证逻辑需要根据OAuth2服务器的接口和规范进行）
//  JwtComponent jwtComponent = new JwtComponent();
//  if (!StringUtils.isEmpty( token)) {
//   try {
//    jwtComponent.defaultRsaVerify(token);
//   } catch (Exception e) {
//    return unauthorized(exchange, "fdsfsd token", HttpStatus.UNAUTHORIZED);
//   }
//   return chain.filter(exchange);
//  } else {
//   // Token无效时返回401 Unauthorized
//   return  unauthorized(exchange, "Missi333ng token", HttpStatus.UNAUTHORIZED);
//  }
// }
// private Mono<Void> unauthorized(ServerWebExchange exchange, String msg, HttpStatus status) {
//  ServerHttpResponse res = exchange.getResponse();
//  res.setStatusCode(status);
//  res.getHeaders().setContentType(MediaType.APPLICATION_JSON);
//  String body = String.format("{\"code\":%d,\"msg\":\"%s\"}", status.value(), msg);
//  DataBuffer buf = res.bufferFactory().wrap(body.getBytes(StandardCharsets.UTF_8));
//  return res.writeWith(Mono.just(buf));
// }
//}
