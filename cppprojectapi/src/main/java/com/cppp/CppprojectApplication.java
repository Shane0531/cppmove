package com.cppp;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;

@SpringBootApplication
public class CppprojectApplication {
	final public static String HOST = "http://168.131.35.110:8080";
	
    public static void main(String[] args) {
        SpringApplication.run(CppprojectApplication.class, args);
    }
}
