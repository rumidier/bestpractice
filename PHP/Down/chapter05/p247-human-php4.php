<?

	class Human { //�ΰ� Ŭ������ ���� �մϴ�.

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

		/* PHP4���� �Ҹ��� �Լ��� �����ϴ�.
		function destruct()
		{
			
		} 
		*/

		function Eat ( $foods ) {
			//�Դ� ������ �Լ��� ����
			echo "��ƿ��<BR>";
		}
		function Walk ( $destination ) {
			//�ȴ� ������ �Լ��� ����
			echo "�ѹ��ѹ�<BR>";
		}
		function Work ( $job ) {
			//���ϴ� ������ �Լ��� ����
			echo "���ɿ���<BR>";
		}
		function Talk ( $words ) {
			//���ϴ� ������ �Լ��� ����
			echo $words . "<BR>";
		}
	}

?>