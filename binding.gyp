{
    "targets": [
        {
            "include_dirs": [
                "<!(node -e \"require('nan')\")"
            ],
            "target_name": "electron-disable-minimize",
            "sources": [],
            "conditions": [
                ['OS=="win"', {'sources':['lib.cc']},  { "sources": ["none.cc"] }],
            ]
        }
    ]
}
