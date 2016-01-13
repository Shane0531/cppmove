package com.cppp;

import java.util.ArrayList;
import java.util.List;

import javax.transaction.Transactional;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.ResponseBody;
import org.springframework.web.bind.annotation.RestController;

import lombok.extern.slf4j.Slf4j;

@RestController
@Transactional
@ResponseBody
@Slf4j
public class MapController {
	@Autowired
	MapRepository mc;
	
	@RequestMapping(value="/map/save", method=RequestMethod.POST)
	public Map postMap(@RequestBody Map map){
		Map m = new Map();
		m.setMap(map.getMap());
		mc.save(m);
		return m;
	}
	
	@RequestMapping("/map")
	public Map RandMap(){
		ArrayList<Map> maplist;
		maplist = (ArrayList<Map>) mc.findAll();
		int rand = (int)(Math.random() * maplist.size());
		return maplist.get(rand);
	}
	
}
