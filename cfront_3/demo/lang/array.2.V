template Array_Sort<int> class

try_array: initial array values:
( 10 )< 3, 5, 6, 7, 9, 12
	14, 17, 27, 128 >

try_array: after assignments:
( 10 )< 3, 5, 6, 7, 12, 14
	17, 27, 27, 27 >

try_array: memberwise initialization
( 10 )< 3, 5, 6, 7, 12, 14
	17, 27, 27, 27 >

try_array: after memberwise copy
( 10 )< 3, 5, 14, 7, 12, 14
	17, 27, 27, 27 >

try_array: after grow
( 16 )< 0, 0, 0, 0, 0, 0
	3, 5, 7, 12, 14, 14
	17, 27, 27, 27 >

template Array_Sort<String> class

try_array: initial array values:
( 7 )< Eeyore, Gopher, Heffalump, Owl, Piglet, Pooh
	Tigger >

try_array: after assignments:
( 7 )< Eeyore, Gopher, Owl, Piglet, Pooh, Pooh
	Pooh >

try_array: memberwise initialization
( 7 )< Eeyore, Gopher, Owl, Piglet, Pooh, Pooh
	Pooh >

try_array: after memberwise copy
( 7 )< Eeyore, Piglet, Owl, Piglet, Pooh, Pooh
	Pooh >

try_array: after grow
( 11 )< <empty>, <empty>, <empty>, <empty>, Eeyore, Owl
	Piglet, Piglet, Pooh, Pooh, Pooh >

