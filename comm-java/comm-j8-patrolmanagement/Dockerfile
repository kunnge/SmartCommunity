FROM crpi-5yw4kk2bxbk3nj6k.cn-hangzhou.personal.cr.aliyuncs.com/01xq/openjdk:8
MAINTAINER yuanzijie
ADD target/comm-j8-patrolmanagement-1.0.0-SNAPSHOT.jar app.jar
ENV JAVA_OPTS="-Xms256m -Xmx256m"
ENV SPRING_ARGS=""
RUN echo "JAVA_OPTS=" $JAVA_OPTS
CMD java $JAVA_OPTS -jar app.jar --logging.file.path=/tmp/logs/spring-boot $SPRING_ARGS