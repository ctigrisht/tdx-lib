## TDX - Typed Data Exchange

### What is TDX?

TDX is a binary format used to exchange and store data in a strongly typed manner,
it supports fixed schemas and data types.

It is the primary data storage format for `vrdb-cpp`, a noSQL relational database.

### Supported data types

- null
- string `UTF-8/16/32`
- int16
- int32
- int64
- int128
- uint16
- uint32
- uint64
- uint128
- float32
- float64
- float128
- decimal `no loss of precision`
- blob
- blob_ref
- json
- document
- guid
- uint64_id
- link_ref

### Storage compatibility scheme

All data is stored in the Little-Endian order to ensure
the compatibility of the stored or transmitted data set

### Format specification

`#MODULE [NAME]` refers to an expandable module for reading clarity, similar to an `#include`

```
#MODULE "DOCUMENT_SET"

SET: "Set of documents, like a wrapper"
DOC: "Individual document containing properties"
PROP: "Property inside a document"

(UINT_8: 0 [{SET} START])  
(UINT_32 [DOCUMENT COUNT])
(module "SCHEMA_GROUP")  
(UINT_64 [{SET} DATA LENGTH])  
(BYTE_ARR [DATA]){
    (each [DOCUMENT]){
        (module "DOCUMENT")
    }
}
```

```
#MODULE "SCHEMA_GROUP"

(UINT_8: 1 [GROUP START])
(UINT_16 [SCHEMA COUNT])
(each [SCHEMA]){
    (module "SCHEMA")
}
(UINT_8: 155 [GROUP END])
```

```
#MODULE "SCHEMA"

(UINT_8: 0 [SCHEMA START])
(UINT_16 [SCHEMA ID])
(UINT_16 [CONSTRAINTS COUNT])
(each [CONSTRAINT]){
    (UINT_8: 0 [START])
    (UINT_16 [ID])
    (UINT_16 [KEY LENGTH])
    (BYTE_ARR [KEY DATA]) // string
    (UINT_8: 155 [END])
}
```

```
#MODULE "DOCUMENT"

(UINT_8: 1 [DOCUMENT START])
(BOOL [IS DOCUMENT NULL])
(if [DOCUMENT NULL]){
    (UINT_8_ARR: 0, 155)
} (else) {
    (module "DOCUMENT_BODY")
}
```

```
#MODULE "DOCUMENT_BODY"

(BOOL [IS HEADER NULL])
(if not [HEADER NULL]){
    (UINT_16 [HEADER LENGTH])
    (BYTE_ARR [HEADER DATA])
}
(UINT_32 [{DOC} DATA LENGTH])
(UINT_16 [{DOC} PROPERTY COUNT])
```

```
#MODULE "DOCUMENT_PROPERTY"
```

```
#MODULE "PROPERTY_VALUE"
```

[//]: # (#### TDX Transmit)

[//]: # ()

[//]: # (#### TDX Storage)