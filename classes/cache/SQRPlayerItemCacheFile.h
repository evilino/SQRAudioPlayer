
//  Created by huanwh on 2017/7/31.

//

#import <Foundation/Foundation.h>

@interface SQRPlayerItemCacheFile : NSObject

@property (nonatomic,copy,readonly) NSString *cacheFilePath;
@property (nonatomic,copy,readonly) NSString *indexFilePath;
@property (nonatomic,assign,readonly) NSUInteger fileLength;
@property (nonatomic,assign,readonly) NSUInteger readOffset;
@property (nonatomic,copy,readonly) NSDictionary *responseHeaders;
@property (nonatomic,readonly) BOOL isCompeleted;
@property (nonatomic,readonly) BOOL isEof;
@property (nonatomic,readonly) BOOL isFileLengthValid;

@property (nonatomic,readonly) NSUInteger cachedDataBound;

+ (instancetype)cacheFileWithFilePath:(NSString *)filePath;
- (instancetype)initWithFilePath:(NSString *)filePath;

+ (NSString *)indexFileExtension;

- (NSRange)cachedRangeForRange:(NSRange)range;
- (NSRange)cachedRangeContainsPosition:(NSUInteger)pos;
- (NSRange)firstNotCachedRangeFromPosition:(NSUInteger)pos;

- (void)seekToPosition:(NSUInteger)pos;
- (void)seekToEnd;

- (NSData *)readDataWithLength:(NSUInteger)length;
- (NSData *)dataWithRange:(NSRange)range;

- (BOOL)setResponse:(NSHTTPURLResponse *)response;
- (BOOL)saveData:(NSData *)data atOffset:(NSUInteger)offset synchronize:(BOOL)synchronize;
- (BOOL)synchronize;

- (void)removeCache;
@end
