<?

$entries = array(
  'FAMILY. 가족' => array(
    'part' => '명사.',
    'definition' => '한집에 사는 개인의 무리인데, 그 구성원은 남자,여자,어린아이,애완견,고양이,애완조,바퀴벌레,집진드기 등이 있다.',
  ),
  'FLY. 파리' => array(
    'part' => '명사.',
    'definition' => '악마에게 충성을 맹세한 하늘의 괴물. 보통 집파리는 파리 중에서도 가장 널리 분포되어 있다',
    'quote' => array(
      '사실 이 생물이야 말로 인류를 중국 대륙에서',
      '페루에 이르기 까지 관망하는 것이다.',
      '집 파리는 온 세상을 구름 처럼 덮고 있으며,',
      '언제 어디서나 태양은 집 파리를 비추고 있다.',
    ),
    'author' => '곤충 백과사전',
  ),
  'FLOP. 변절하다' => array(
    'part' => '동사.',
    'definition' => '돌연히 자신의 견해를 바꾸어 다른 패에 드는 것. 변절의 가장 유명한 예는 타르수스 출신의 사울이다.(사도 바울의 개종 전 이름)',
  ),
  'FORK. 포크' => array(
    'part' => '명사.',
    'definition' => '주로 죽은 동물을 입 속에 넣는데 쓰는 도구',
    'quote' => array(
      '예전에는 나이프가 같은 목적으로 쓰였으며,',
      '지금도 나이프가 포크보다 낫다고 생각하는 분들이 많다',
      '그러나 이들도 포크를 전혀 거부하는 것이 아니라,',
      '나이프를 쓸 때의 보조 수단으로 포크의 도움을 받기도 한다.',
    ),
  ),
  'FOREFINGER. 검지 손가락' => array(
    'part' => '명사.',
    'definition' => '두 사람의 악인을 지적할 때 흔히 쓰는 손가락.',
  ),
  'FRISKY. 주책없는' => array(
    'part' => '형용사.',
    'definition' => '나이 사십에도 체통 없이 구는 경솔한 자가 하는 짓. 어딘지 여자처럼 행동하여 남성다움을 잃은 내리막길 인간과도 같은.',
  ),
  'FROG. 개구리' => array(
    'part' => '명사.',
    'definition' => '식용에 적합한 피부와 다리가 달린 파충류.',
    'quote' => array(
      '개구리는 좋은 성대를 지니고 있으나',
      '들어줄 청중이 없는 부지런한 가수다.',
      '그의 독특한 오페라 가사는 단순하고 간결하고 효과적이다',
      '말의 네 발굽에는 개구리(말의 발굽이 개구리 모습과 닮았다고 봄)가,',
      '달려 있는데, 이것은 오묘한 자연의 섭리가 아닐까. 특히 장애물 경주',
      '에서는 개구리의 솜씨가 탁월하다',
    ),
    'author' => '파충류 백과사전',
  ),
  'FRYING-PAN. 프라이팬' => array(
    'part' => '명사.',
    'definition' => '여자가 징벌 장소인 부엌에서 쓰는 형벌 도구의 하나. 이 도구의 유용성은 이 세상에 국한되는 것이 아니라 내세에까지 영향을 미칠것으로 보인다',
  ),
);

foreach ($entries as $term => $entry) {
  if (strpos($term, strtoupper($_REQUEST['term'])) !== FALSE) {
    $html = '<div class="entry">';

    $html .= '<h3 class="term">';
    $html .= $term;
    $html .= '</h3>';

    $html .= '<div class="part">';
    $html .= $entry['part'];
    $html .= '</div>';

    $html .= '<div class="definition">';
    $html .= $entry['definition'];
    if (isset($entry['quote'])) {
      foreach ($entry['quote'] as $line) {
	$html .= '<div class="quote-line">'.$line.'</div>';
      }
      if (isset($entry['author'])) {
	$html .= '<div class="quote-author">'.$entry['author'].'</div>';
      }
    }
    $html .= '</div>';
    $html .= '</div>';

    print ($html);
  }
}
?>
