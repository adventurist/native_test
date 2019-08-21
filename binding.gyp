{
  'targets': [
    {
      'target_name': 'lerna_test',
      'defines': [ 'NAPI_DISABLE_CPP_EXCEPTIONS' ],
      'include_dirs': [
        './src/cpp'
      ],
      'sources' : [
        'src/cpp/main.cpp',
      ],
    }
  ]
}
