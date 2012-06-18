<?
   $Val1 = "가나다라마바사아아아아아\n아자차카야제커거\n미나다가라서여";
   $word = split("\n", $Val1);
   $arr_cnt = count($word);
   $full_arr = array();

   for ($i = 0; $i <= $arr_cnt-1; $i++) {
	$str = str_split_unicode($word[$i], 10);
	if ($full_arr) {
		$full_arr = array_merge((array)$full_arr, (array)$str);
	}
	else {
		$full_arr = array_merge((array)$str);
	}
   }

    if (count($full_arr) >= 4) {
	    echo "Error"."\n";
	    print_r($full_arr);
	    exit;
    }

    print_r($full_arr);

function str_split_unicode($str, $l) {
    $ret = array();
    $len = mb_strlen($str, "UTF-8");
    for ($i = 0; $i < $len; $i += $l) {
        $ret[] = mb_substr($str, $i, $l, "UTF-8");
    }
    return $ret;
}
?>
