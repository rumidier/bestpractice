<?
	for ( $i =0; $i < 3; $i++ )
	{
		echo "첫 번째 루프<br>";
		while (1)
		{
			echo "두 번째 루프<br>";
			while (1)
			{
				echo "세 번째 루프<br>";
				continue 3;
			}
			echo "나도 출력되고 싶은데잉~<br>";
		}
		echo "나도 나오게 해줘 제발~ ㅜㅜ<br>";
	}
?>