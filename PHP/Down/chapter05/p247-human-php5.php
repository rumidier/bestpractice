<?

	class Human { //�ΰ� Ŭ������ ���� �մϴ�.

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
			//�Դ� ������ �Լ��� ����
			echo "��ƿ��<BR>";
		}
		public function Walk ( $destination ) {
			//�ȴ� ������ �Լ��� ����
			echo "�ѹ��ѹ�<BR>";
		}
		public function Work ( $job ) {
			//���ϴ� ������ �Լ��� ����
			echo "���ɿ���<BR>";
		}
		public function Talk ( $words ) {
			//���ϴ� ������ �Լ��� ����
			echo $words . "<BR>";
		}
	}
?>