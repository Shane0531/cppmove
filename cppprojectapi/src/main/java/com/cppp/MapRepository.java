package com.cppp;

import org.springframework.boot.autoconfigure.EnableAutoConfiguration;
import org.springframework.data.jpa.repository.config.EnableJpaRepositories;
import org.springframework.data.repository.CrudRepository;
import org.springframework.stereotype.Repository;

@Repository
@EnableAutoConfiguration
@EnableJpaRepositories
public interface MapRepository  extends CrudRepository<Map,String>{

}
