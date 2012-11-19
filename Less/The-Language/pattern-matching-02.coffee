.mixin (@a) when (lightness(@a) >= 50%) {
  background-color: black;
}

.mixin (@a) when (lightness(@a) < 50%) {
  background-color: white
}

.mixin (@a) {
  color: @a;
}

.class1 { .mixin(#ddd) }
.class2 { .mixin(#555) }
