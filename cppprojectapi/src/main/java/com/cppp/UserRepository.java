package com.cppp;

import java.util.Collection;

import org.springframework.boot.autoconfigure.EnableAutoConfiguration;
import org.springframework.data.jpa.repository.config.EnableJpaRepositories;
import org.springframework.data.repository.CrudRepository;
import org.springframework.stereotype.Repository;



@Repository
@EnableAutoConfiguration
@EnableJpaRepositories
public interface UserRepository extends CrudRepository<User,String>{
	User findByIdx(int idx);
}
