// Generated by CoffeeScript 1.4.0
(function() {
  var sum,
    __slice = [].slice;

  sum = function() {
    var nums, result;
    nums = 1 <= arguments.length ? __slice.call(arguments, 0) : [];
    result = 0;
    nums.forEach(function(n) {
      return result += n;
    });
    return result;
  };

}).call(this);
