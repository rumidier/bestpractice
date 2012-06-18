<?
  class Human {
    public $Name;
    public $Age;
    public $Height;
    public $Weight;

    function __construct ($pName, $pAge = 1, $pHeight = 50, $pWeight = 3.5) {
      $this->Name   = $pName;
      $this->Age    = $pAge;
      $this->Height = $pHeight;
      $this->Weight = $pWeight;
    }
    function __destruct()
      { $this->Talk("창문을 닫아주오!"); }
    public function Eat( $foods )
      { echo "우걱우걱~ 맛있는 " . $foods . "</br />"; }
    public function Walk( $destination )
      { echo "뚜벅 뚜벅" . $destination . "까지 걸어요.<br />"; }
    public function Work( $job )
      { echo $words . "<br />"; }
    public function Talk( $words )
      { echo $words . "<br />"; }
  }
?>
