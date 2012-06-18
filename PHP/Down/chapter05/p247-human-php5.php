<?

	class Human { //인간 클래스를 정의 합니다.

		public $Name;
		public $Age;
		public $Height;
		public $Weight;
		public $DyingWish;

		public function __construct($pName, $pAge = 1, $pHeight=50, $pWeight=3.5)
		{
			$this->Name = $pname;
			$this->Age = $pAge;
			$this->Height = $pHeight;
			$this->Weight = $pWeight;
		}

		public function destruct()
		{
			Talk( $this->DyingWish );
		}

		public function Eat ( $foods ) {
			//먹는 행위를 함수로 정의
			echo "우걱우걱<BR>";
		}
		public function Walk ( $destination ) {
			//걷는 행위를 함수로 정의
			echo "뚜벅뚜벅<BR>";
		}
		public function Work ( $job ) {
			//일하는 행위를 함수로 정의
			echo "열심열심<BR>";
		}
		public function Talk ( $words ) {
			//말하는 행위를 함수로 정의
			echo $words . "<BR>";
		}
	}
?>