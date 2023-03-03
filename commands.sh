# for all files named “main.cc” in current directory and its subdirecties, 
# insert this line of text: 
#       \n#pragma GCC diagnostic ignored "-Wunused-variable” 
# at the second line.
# Note: replace the argument '-i' with '-e' to preview the changing results
find . -name "main.cc" -exec gsed -i '2i\\n#pragma GCC diagnostic ignored "-Wunused-variable"' {} \;



