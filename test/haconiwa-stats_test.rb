##
## Haconiwa Test
##

assert("Haconiwa::Stats#hello") do
  t = Haconiwa::Stats.new "hello"
  assert_equal(Haconiwa::Stats, t.class)
end
