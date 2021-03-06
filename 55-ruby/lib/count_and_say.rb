class CountAndSay
  
  attr_accessor :first
  
  def initialize(first)
    @first = first
  end
    
  def [](index)
    if index == 1
      @first
    elsif index <= 3
      (number_of(@first.to_s, self[index-1].to_s).to_s + '1').to_i
    else
      last_step = self[index-1].to_s
      fourth_term = ""
      last_step.split("").each do |c|
        fourth_term += number_of(c, last_step).to_s + c 
      end
      
      fourth_term.to_i
    end
  end
  
end

def number_of(char , string)
  string.count(char)
end