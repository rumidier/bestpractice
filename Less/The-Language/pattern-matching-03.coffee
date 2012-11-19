.truth (@a) when (@a) { ... }
.truth (@a) when (@a = true) { ... }

.class {
  .truth(40);
}

.mixin (@a) when (@a > 10), (@a < -10) { ... }

@media: mobile;

.mixin (@a) when (@media = mobile) { ... }
.mixin (@a) when (@media = desktop) { ... }

.max (@a, @b) when (@a > @b) { width: @a }
.max (@a, @b) when (@a < @b) { width: @b }

.mixin (@a, @b: 0) when (isnumber(@b)) { ... }
.mixin (@a, @b: black) when (iscolor(@b)) { ... }

//iscolor
//isnumber
//isstring
//iskeyword
//isurl
--
// ispixel
// ispercentage
// isem

.mixin (@a) when (isnumber(@a)) and (@a > 0) { ... }
.mixin (@b) when not (@b > 0) { ... }
