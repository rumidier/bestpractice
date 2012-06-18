<?php

$entries = array(
  'EDITOR' => array(
    'part' => '명사.',
    'definition' => '편집자: 재판관의 역할을 수행하나 은화 한 닢으로 회유당하기 쉬운 인물.',
    'quote' => array(
      '엄격한 검열관으로 도덕적인 것을 강조하지만,',
      '지극히 관대한 면도 있어서 남의 덕행과 함께 ',
      '자신의 비행도 눈감아 버리는 버릇이 있다.',
      '천둥 벼락 같은 힐책, 경고를 주위에 마구 퍼부으며,',
      '개 꼬리 끝에 매단 한 다발의 폭죽이 터지듯 불만을 터트린다.',
      '그러다가도 어느새 부드럽고 아름다운 가락으로 노래를 부른다"',
      '그것은 마치 샛별에게 기도를 드리는 조랑말의',
      '속상임과도 같이 유순하기 이를데 없다',
    ),
    'author' => '어느 작가',
  ),
  'EDIBLE' => array(
    'part' => '형용사.',
    'definition' => '식용의: 예를 들면, 두꺼비에게는 구더기가, 뱀에게는 두꺼비가, 돼지에게는 뱀이, 인간에게는 돼지가, 그리고 구더기에게는 사람이 그렇듯이, 먹기에 알맞고 건강에 좋은',
  ),
  'EDUCATION' => array(
    'part' => '명사.',
    'definition' => '교육: 자기 이해력에 한계가 있다는 것을 현자에게는 열어 보이고 우자에게는 감추는 것.',
  ),
  'ELOQUENCE' => array(
    'part' => '명사.',
    'definition' => '언변: 흰색을 희게 보이는 빛갈이라고 바보들을 말로 납득시키는 기술. 어떤 색이든 희다고 여기게 하는 천부적 재능도 포함된다..',
  ),
  'ELYSIUM' => array(
    'part' => '명사.',
    'definition' => '엘리시온: 고대인이 어리석게도 선남선녀의 혼이 사후에 안주할 곳으로 믿었던 낙원.이 무익한 우화는 초기 기독교인에 의하여 지상에서 말끔히 일소 되었다. 영혼들이여 천국에서 행복할 지어다.',
  ),
  'EMOTION' => array(
    'part' => '명사.',
    'definition' => '감동: 심장의 피가 머리로 올라오는 것이 원인이 되어 생기는 육체를 소모시키는 병. 때로는 눈에서 염화나트륨 용액을 부단히 방출하는 증세를 수반하기도 한다.',
  ),
  'ENVY' => array(
    'part' => '명사.',
    'definition' => '질투: 가장 비열한 능력에 알맞은 경쟁의식.',
  ),
  'EPAULET' => array(
    'part' => '명사.',
    'definition' => '견장: 장식이 달린 일종의 기장.어느 장교와 그의 적-그 장교가 죽으면 승진하는 사람-을 식별하는 데 도움이 된다.',
  ),
  'EXPERIENCE' => array(
    'part' => '명사.',
    'definition' => '경험: 우리에게 이미 습관처럼 되어버린 어리석은 행동이 실은 바람직하지 못한 버릇이라는 것을 깨닫게 해주는 지혜:',
    'quote' => array(
      '안개 짙은 밤에 여행하다가,',
      '진흙 수렁에 목밑까지 빠져버린 사람에게 경험이란,',
      '서광처럼 가지 말았어야 할 길을 비춘다',
    ),
  )
);

if (isset($entries[strtoupper($_REQUEST['term'])])) {
  $entry = $entries[strtoupper($_REQUEST['term'])];
  
  $html = '<div class="entry">';

  $html .= '<h3 class="term">';
  $html .= strtoupper($_REQUEST['term']);
  $html .= '</h3>';

  $html .= '<div class="part">';
  $html .= $entry['part'];
  $html .= '</div>';

  $html .= '<div class="definition">';
  $html .= $entry['definition'];
  if (isset($entry['quote'])) {
    $html .= '<div class="quote">';
    foreach ($entry['quote'] as $line) {
      $html .= '<div class="quote-line">'. $line .'</div>';
    }
    if (isset($entry['author'])) {
      $html .= '<div class="quote-author">'. $entry['author'] .'</div>';
    }      
    $html .= '</div>';
  }
  $html .= '</div>';
  
  $html .= '</div>';
  
  print($html);
}

