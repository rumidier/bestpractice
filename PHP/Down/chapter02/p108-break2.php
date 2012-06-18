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
				break 2;
			}
			echo "나도 출력되고 싶은데잉~<br>";
		}
		echo "나는 출력되지롱~<br>";
	}
?>