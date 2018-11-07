{
  "targets": [
    {
      "include_dirs": [
        "<!(node -e \"require('nan')\")"
      ],
      "target_name": "disable-minimize",
      "sources": [ "lib.cc" ]
    }
  ]
}