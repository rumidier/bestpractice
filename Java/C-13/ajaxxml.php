<?php

// 검색 문자열을 받지 않으면 검색을 수행할 수 없다.
if(empty($_GET['state'])) {
	echo "<city>No State Sent</city>";
} else {
	// 검색의 처음과 끝에서 공백 문자를 제거한다.
	$search = trim($_GET['state']);

	switch($search) {
		case "MO" :
			$result = "<city><value>stlou</value><title>St.Louis</title></city>" .
				  "<city><value>kc</value><title>Kansas City</title></city>";
			break;

		case "WA" :
			$result = "<city><value>seattle</value><title>Seattle</title></city>" .
				  "<city><value>spokane</value><title>Spokane</title></city>" .
				  "<city><value>olympia</value><title>Olympia</title></city>";
			break;

		case "CA" :
			$result = "<city><value>sanfran</value><title>San Francisco</title></city>" .
				  "<city><value>la</value><title>Los Angeles</title></city>" .
				  "<city><value>barcamp</value><title>BarCamp</title></city>";
			break;

		case "ID" :
			$result = "<city><value>boise</value><title>Boise</title></city>";
			break;

		default :
			$result = "<city><value></value><title>No Cities Found</title></city>";
			break;
	}

	$result = '<?xml version="1.0" encoding="UTF-8" ?>' . "<cities>" . $result . "</cities>";
	header("Content-Type: text/xml; charset=UTF-8");
	echo $result;
}
?>
