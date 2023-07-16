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
- datetime
- timespan
- blob
- blob_ref
- json
- document
- guid
- uint64_id
- array `dynamic typed array`
- link_ref

### Storage compatibility scheme

All data is stored in the Little-Endian order to ensure
the compatibility of the stored or transmitted data set

### Format specification

#### General terms and definitions

- Document: An individual entity representing a data structure
- Schema: A definition of the data structure of a document, composed of constraints
- Constraint: An individual constrain of a schema, mapping an ID and data type to a property
- Document Set: A set/list of documents containing multiple constraint schemas in the header
- Property: An ID/Value pair, part of a document
- Fixed length type: A data type with a fixed byte size, such as an `int32` or `float64`
- Variable length type: A data type with a dynamic size, such as a `string`

#### Specification details

`#MODULE [NAME]` refers to an expandable module for reading clarity, similar to an `#include`

```
#MODULE "DOCUMENT_SET"

SET: "Set of documents, like a wrapper"
DOC: "Individual document containing properties"
PROP: "Property inside a document"

(UINT_8: 0 [{SET} START])  
(UINT_32 [DOCUMENT COUNT])
(module "SCHEMA_GROUP")  
(UINT_64 [{SET} DATA LENGTH]) // allows for skipping of data
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
    (UINT_8_ARR [DATA TYPE])
    (UINT_16 [KEY LENGTH])
    (BYTE_ARR [KEY DATA]) // string
    (UINT_8: 155 [END])
}
```

```
#MODULE "DOCUMENT"

(UINT_8: 1 [START])
(BOOL [IS DOCUMENT NULL])
(if [DOCUMENT NULL]){
    (UINT_32 [LENGTH OF NULL PADDING - 1])
    (UINT_8_ARR: 155)
} (else) {
    (module "DOCUMENT_BODY")
}
(UINT_8: 254 [END])
```

```
#MODULE "DOCUMENT_BODY"

(BOOL [IS HEADER NULL])
(if not [HEADER NULL]){
    (UINT_16 [HEADER LENGTH])
    (BYTE_ARR [HEADER DATA])
}
(UINT_16 [SCHEMA ID])
(UINT_16 [{DOC} PROPERTY COUNT])
(UINT_32 [{DOC} DATA LENGTH])
(each [PROPERTY]){
    (module "DOCUMENT_BOUND_PROPERTY")
}
(UINT_32 [LINKS DATA SIZE])
(UINT_16 [LINKS COUNT])
(each [LINK]){
    (module "LINK_REF")
}
```

```
#MODULE "DOCUMENT_BOUND_PROPERTY"

(UINT_16 [CONSTRAINT ID])
(BYTE_ARR [DATA TYPE]) // in order to skip data array faster
(BOOL [IS VALUE NULL])
(if [VALUE NULL]) {
    (UINT_8: 0)
} (else) {
    (switch {DATA_TYPE}){
        (module "{DATA_TYPE}_VALUE")
    }
}
```

```
#MODULE "DOCUMENT_FREE_PROPERTY"

(UINT_16 [CONSTRAINT ID])
(BYTE_ARR [DATA TYPE]) // in order to skip data array faster
(BOOL [IS VALUE NULL])
(if [VALUE NULL]) {
    (UINT_8: 0)
} (else) {
    (switch {DATA_TYPE}){
        (module "{DATA_TYPE}_VALUE")
    }
}
```

```
#MODULE "{string_utf-8}_VALUE"
#MODULE "{string_utf-16}_VALUE"
#MODULE "{string_utf-32}_VALUE"

(UINT_32 [DATA LENGTH])
(BYTE_ARR [DATA ARRAY])
```

```
#MODULE "{intX}_VALUE"
#MODULE "{uintX}_VALUE"
#MODULE "{floatX}_VALUE"
#MODULE "{decimal}_VALUE"

([TYPE FIXED LENGTH VALUE BYTES ARRAY])
```

```
#MODULE "{datetime}_VALUE"

(UINT_64 [DATETIME])
(UINT_16 [TIMEZONE])
```

```
#MODULE "{timespan}_VALUE"

(INT_64 [TIMESPAN])
```
```
#MODULE "{blob}_VALUE"

(UINT_32 [DATA LENGTH])
(BYTE_ARR [DATA ARRAY])
```

```
#MODULE "{blob_ref}_VALUE"

(UINT_32 [PARITION ID])
(GUID [BLOB FILE ID])
```

```
#MODULE "{json}_VALUE"

(UINT_32 [DATA LENGTH])
(BYTE_ARR [DATA ARRAY])
```

```
#MODULE "{document}_VALUE"

(BOOL [IS BOUND TO CONSTRAINT])
(UINT_32 [DOCUMENT DATA LENGTH]) // to skip the data
(if [BOUND TO CONSTRAINT]) {
    (module "BOUND_MEMBER_DOCUMENT")
} (else) {
    (module "FREE_MEMBER_DOCUMENT")
}
```

```
#MODULE "BOUND_MEMBER_DOCUMENT"

(UINT_16 [PROPERTY COUNT])
(each [PROPERTY]){
    (module "DOCUMENT_BOUND_PROPERTY")
}
```

```
#MODULE "FREE_MEMBER_DOCUMENT"

(UINT_16 [PROPERTY COUNT])
(each [PROPERTY]){
    (module "DOCUMENT_FREE_PROPERTY")
}
```

```
#MODULE "{guid}_VALUE"

(GUID [16 BYTE ARRAY])
```

```
#MODULE "{uint64_id}_VALUE"

(UINT_64 [8 BYTE ARRAY])
```

```
#MODULE "{array}_VALUE"

(UINT_32 [VALUES COUNT])
(each [VALUE]) {
    (BYTE_ARR[2] [TYPE CODE])
    (switch [DATA_TYPE]){
        (module "{DATA_TYPE}_VALUE")
    }
}
```

```
#MODULE "LINK_REF"

(UINT_64 [FOREIGN TABLE ID])
(UINT_16 [FOREIGN CONSTRAINT ID])
(BYTE_ARR[2] [TYPE CODE])
(switch for [DATA_TYPE]){
    (module "{DATA_TYPE}_VALUE")
}

(BOOL [IS CONSTRAINED LINK])
(if [CONSTRAINED LINK]){
    (UINT_32 [LINK CONSTRAINT ID])
} (else) {
    (UINT_32 [STRING LENGTH])
    (BYTE_ARR [STRING DATA ARRAY]) // UTF-8 ONLY
}
```


### Data types byte maps

Data types are 2 bytes in length

- null [0, 1]
- string UTF-8 [10, 8]
- string UTF-16 [10, 16]
- string UTF-32 [10, 32]
- int16 [20, 16]
- int32 [20, 32]
- int64 [20, 64]
- int128 [20, 128]
- uint16 [21, 16]
- uint32 [21, 32]
- uint64 [21, 64]
- uint128 [21, 128]
- float32 [30, 32]
- float64 [30, 64]
- float128 [30, 128]
- decimal [31, 128]
- datetime [41, 0]
- timespan [41, 1]
- blob [50, 0]
- blob_ref [50, 10]
- json [60, 0]
- document [60, 1]
- guid [70, 0]
- uint64_id [70, 1]
- array [100, 0]
- link_ref [254, 0]

[//]: # (#### TDX Transmit)

[//]: # ()

[//]: # (#### TDX Storage)