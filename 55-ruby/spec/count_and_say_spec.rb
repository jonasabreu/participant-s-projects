require 'rubygems'
require 'spec'
require 'lib/count_and_say'

describe 'count-and-say' do

  it "should guive the correct, first number" do
    seq = CountAndSay.new(1)
    seq.first.should == 1
  end

  it "should give the second number, when the firs is one" do
    seq = CountAndSay.new(1)
    seq.second.should == 11
  end

end