template Array<int> class

try_array: initial array values:
( 10 )< 12, 7, 14, 9, 128, 17
	6, 3, 27, 5 >

try_array: after assignments:
( 10 )< 128, 7, 14, 9, 128, 128
	6, 3, 27, 3 >

try_array: memberwise initialization
( 10 )< 128, 7, 14, 9, 128, 128
	6, 3, 27, 3 >

try_array: after memberwise copy
( 10 )< 128, 7, 128, 9, 128, 128
	6, 3, 27, 3 >

try_array: after grow
( 16 )< 128, 7, 128, 9, 128, 128
	6, 3, 27, 3, 0, 0
	0, 0, 0, 0 >

template Array<double> class

try_array: initial array values:
( 5 )< 12.3, 7.9, 14.6, 9.8, 128 >

try_array: after assignments:
( 5 )< 14.6, 7.9, 14.6, 9.8, 7.9 >

try_array: memberwise initialization
( 5 )< 14.6, 7.9, 14.6, 9.8, 7.9 >

try_array: after memberwise copy
( 5 )< 14.6, 14.6, 14.6, 9.8, 7.9 >

try_array: after grow
( 8 )< 14.6, 14.6, 14.6, 9.8, 7.9, 0
	0, 0 >

template Array<String> class

try_array: initial array values:
( 7 )< Eeyore, Pooh, Tigger, Piglet, Owl, Gopher
	Heffalump >

try_array: after assignments:
( 7 )< Tigger, Pooh, Tigger, Tigger, Owl, Gopher
	Eeyore >

try_array: memberwise initialization
( 7 )< Tigger, Pooh, Tigger, Tigger, Owl, Gopher
	Eeyore >

try_array: after memberwise copy
( 7 )< Tigger, Tigger, Tigger, Tigger, Owl, Gopher
	Eeyore >

try_array: after grow
( 11 )< Tigger, Tigger, Tigger, Tigger, Owl, Gopher
	Eeyore, <empty>, <empty>, <empty>, <empty> >

