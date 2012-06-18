var entries = [
  {
    "term": "CALAMITY. 재난",
    "part": "명사.",
    "definition": "세상일은 우리네 인간의 힘이 미치지 못하는 데에 있음을 예사롭지 않은 방법으로 분명하게 느끼게 해주는 것. 재난에는 자기 자신의 불행과 타인에게 일어나는 행복. 이 두 종류가 있다."
  },
  {
    "term": "CANNIBAL. 식인종",
    "part": "명사.",
    "definition": "돼지고기 도입 이전의 소박한 미각을 잃지 않고 그 무렵의 특유한 자연식을 고수해 오고 있는 오래된 미식가."
  },
  {
    "term": "CHILDHOOD. 아동기",
    "part": "명사.",
    "definition": "인간의 생애에 있어서 백치 같은 유아기와 잘못을 일삼는 청소년기의 중간에 위치한 인생의 한구간. 두 단계를 건너면 성년의 죄악. 세 단계를 건너면 노년의 후회가 온다."
  },
  {
    "term": "CLARINET. 클라리넷",
    "part": "명사.",
    "definition": "귀에 솜을 넣은 사람이 조작하는 고문도구. 클라리넷보다 더욱 참기 어려운 고문 도구가 있다. 바로 두 개의 클라리넷."
  },
  {
    "term": "COMFORT. 안락",
    "part": "명사.",
    "definition": "이웃이 불안해하는 상태를 조용히 바라보면서 갖는 쾌적한 마음."
  },
  {
    "term": "CORSAIR. 해적",
    "part": "명사.",
    "definition": "바다의 정치꾼."
  }
];

var html = '';

$.each(entries, function() {
    html += '<div class="entry">';
    html += '<h3 class="term">' + this['term'] + '</h3>';
    html += '<div class="part">' + this['part'] + '</div>';
    html += '<div class="definition">' + this['definition'] + '</div>';
    html += '</div>';
});

$('#dictionary').html(html);
