MRuby::Build.new do |conf|
  toolchain :gcc
  conf.gembox 'default'
  conf.gem '../haconiwa-stats'
  conf.enable_test
end
