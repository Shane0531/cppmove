package com.cppp;


import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.Id;

import lombok.Data;

@Data
@Entity
public class Map {
	@Id
	@GeneratedValue
	int idx;
	String map;
}
