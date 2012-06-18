<?

	class Human { //인간 클래스를 정의 합니다.

		var $Name;
		var $Age;
		var $Height;
		var $Weight;
		var $DyingWish;

		function Human($pName, $pAge = 1, $pHeight=50, $pWeight=3.5)
		{
			$this->Name = $pName;
			$this->Age = $pAge;
			$this->Height = $pHeight;
			$this->Weight = $pWeight;
		}

		/* PHP4에는 소멸자 함수가 없습니다.
		function destruct()
		{
			
		} 
		*/

		function Eat ( $foods ) {
			//먹는 행위를 함수로 정의
			echo "우걱우걱<BR>";
		}
		function Walk ( $destination ) {
			//걷는 행위를 함수로 정의
			echo "뚜벅뚜벅<BR>";
		}
		function Work ( $job ) {
			//일하는 행위를 함수로 정의
			echo "열심열심<BR>";
		}
		function Talk ( $words ) {
			//말하는 행위를 함수로 정의
			echo $words . "<BR>";
		}
	}

?>