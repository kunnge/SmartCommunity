FROM openjdk:8
MAINTAINER kunge
ADD target/comm-j6-datamanagement-1.0.0-SNAPSHOT.jar app.jar
ENV JAVA_OPTS="-Xms256m -Xmx256m"
ENV SPRING_ARGS=""
RUN echo "JAVA_OPTS=" $JAVA_OPTS
CMD java $JAVA_OPTS -jar app.jar logging.file.path=/tmp/logs/spring-boot $SPRING_ARGS