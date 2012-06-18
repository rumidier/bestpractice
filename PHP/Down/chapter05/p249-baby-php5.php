<?
	/* Human 클래스를 여기에 삽입 */
	include "p247-human-php4.php";

	//인간 클래스를 상속받아 아기 클래스를 정의 합니다.
	class Baby Extends Human { 

		function 모유먹기 () {
			//모유를 먹는 행위를 함수로 정의
			echo "냠냠냠~<BR>";
		}

		function 천사와대화 () {
			//천사와 대화하는 행위를 함수로 정의
			echo "옹알~ 옹알~<BR>";
		}
	}

	//아기 클래스를 이용해 재민이 객체를 생성
	$재민 = new Baby('재민');
	$재민->천사와대화(); // 옹알~ 옹알~
?>