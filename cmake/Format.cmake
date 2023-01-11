function(Format target directory)
    find_program(CLANG-FORMAT_PATH clang-format)
    if(CLANG-FORMAT_PATH)
        set(EXPRESSION hpp cpp)
        list(TRANSFORM EXPRESSION PREPEND "${directory}/*.")
        file(GLOB_RECURSE SOURCE_FILES FOLLOW_SYMLINKS
            LIST_DIRECTORIES false ${EXPRESSION}
        )
        add_custom_command(TARGET ${target} PRE_BUILD COMMAND
            ${CLANG-FORMAT_PATH} -i --style=file ${SOURCE_FILES}
        )
    endif()
endfunction()
