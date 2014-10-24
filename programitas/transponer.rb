#!/Users/jonathaneidelman/.rvm/rubies/ruby-2.1.3/bin/ruby

def transpose(matrix)
  for i in 0..matrix.count - 1
    for j in i..matrix[i].count - 1
      tmp = matrix[i][j]
      matrix[i][j] = matrix[j][i]
      matrix[j][i] = tmp
      puts "se cambio #{tmp} por #{matrix[i][j]}"
    end
  end
  return matrix
end

#main

mat = [[1,2,3],[4,5,6],[7,8,9]]

mat = transpose(mat)

p mat
