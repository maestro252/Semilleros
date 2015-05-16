#!/Users/jonathaneidelman/.rvm/rubies/ruby-2.1.3/bin/ruby

class Day
 attr_accessor :name, :num_id

  def initialize(name = "domingo", num_id = 1)
    @name = name
    @num_id = num_id
  end
end

#main

day = Day.new "lunes", 2
puts "El día es #{day.name}, que corresponde al dia #{day.num_id} de la semana."
