SET(target_name Octree)
project(${target_name})

SET(CPP_FILES
	main.cpp
	Octree.hpp

)

SET(HEAD_FILES
)


add_executable(${target_name} ${CPP_FILES} ${HEAD_FILES})


