package com.cppp;

import java.util.Collection;

import javax.transaction.Transactional;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.ResponseBody;
import org.springframework.web.bind.annotation.RestController;

import lombok.extern.slf4j.Slf4j;

@RestController
@Transactional
@ResponseBody
@Slf4j
public class UserController {
	@Autowired
	UserRepository ur;
	
	@RequestMapping("/user")
	public Iterable<User> list_u(){
	return ur.findAll();
	}
	
	
	@RequestMapping(value="/user/save", method=RequestMethod.POST)
	public User postUser(@RequestBody User user1){
		User user = new User();
		user.setName(user1.getName());
		user.setPassword(user1.getPassword());
		ur.save(user);
		return user;
	}
	
	@RequestMapping(value = "/score",method=RequestMethod.PUT)
	public void UpScore(@RequestParam int idx){
		User user = new User();
		user = ur.findByIdx(idx);
		user.setPoint(user.getPoint() + 5);
		ur.save(user);
	}
	
}
