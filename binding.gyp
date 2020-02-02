{
    "targets": [
        {
            "include_dirs": [
                "<!(node -e \"require('nan')\")"
            ],
            "target_name": "electron-disable-minimize",
            "sources": ["lib.cc"]
        }
    ]
}
