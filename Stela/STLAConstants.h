//
//  Constants.h
//  Stela
//
//  Created by Justin Loew on 1/5/15.
//  Copyright (c) 2015 Justin Loew. All rights reserved.
//

#ifndef Stela_Constants_h
#define Stela_Constants_h


/// The Alchemy API key that powers Stela's ability to parse webpages into text.
extern NSString * const API_KEY;
/// The URL of the Alchemy API that powers Stela's ability to parse webpages into text.
extern NSString * const API_URL;

/// The UUID of the Pebble app, given by its metadata. Used by PebbleKit to open the app.
extern NSString * const stelaUUIDString;

/// The URL to load on the app's first launch.
extern NSString * const kDefaultURL;

/// The maximum size of a message that a Pebble can send or receive, in bytes.
extern NSUInteger const kPebbleMaxMessageSize; // actual max size is ~255, but I'll allow for overhead

/// The unique error domain for all errors generated by Stela.
extern NSString * const STLAErrorDomain __unused;

/// The name of the notification that is fired each time a watch connects or
/// disconnects.
extern NSString * const STLAWatchConnectionStateChangeNotification;

/// The key for the @c userInfo dictionary of the notification. The value for this key
/// is a BOOL representing whether the watch is now connected, wrapped in a NSNumber.
extern NSString * const kWatchConnectionStateChangeNotificationBoolKey;


/// The keys used for sending messages between the watch and the phone.
typedef NS_ENUM(uint32_t, AppMessageKey) {
	/// For reporting an error, as a string.
	ERROR_KEY = 0,
	
	/// Reset command.
	/// Sent by the phone when a new article will be sent.
	/// Never sent by the watch.
	RESET_KEY = 1,
	
	/// Sent by the phone to set the maximum number of words in each block.
	/// Sent by the watch to query the maximum block size.
	TEXT_BLOCK_SIZE_KEY = 2,
	
	/// Sent by the phone to convey the number of blocks in the entire article.
	/// Sent by the watch to query the block count.
	TOTAL_NUMBER_OF_BLOCKS_KEY = 3,
	
	/// The number of words contained in just the current message.
	/// Sent by the phone, in the same message as an array of strings.
	/// Never sent by the watch.
	APPMESG_NUM_WORDS_KEY = 4,
	
	/// Used to send the index of the first word within the text block.
	/// In other words, it's where in the block to insert the words in this message.
	/// Sent by the phone, in the same message as an array of strings.
	/// Never sent by the watch.
	APPMESG_WORD_START_INDEX_KEY = 5,
	
	/// Holds the index of the block that the words in the current message belong in.
	/// Sent by the phone, in the same message as an array of strings.
	/// Sent on its own by the watch to request a block be sent over from the phone.
	APPMESG_BLOCK_NUMBER_KEY = 6,
	
	/// Used to send the dictionary key of the first word within this message.
	/// Sent by the phone, in the same message as an array of strings.
	/// Never sent by the watch.
	APPMESG_FIRST_WORD_KEY = 7,
	
	/// For sending the version of Stela.
	VERSION_MAJOR_KEY = 8,
	
	/// For sending the version of Stela.
	VERSION_MINOR_KEY = 9,
	
	/// For sending the version of Stela.
	VERSION_PATCH_KEY = 10,
	
	/// The value stored for this key in the dict of this message is the first word.
	/// Subsequent words should be stored for increasing keys from this key.
	/// This value is always APPMESG_FIRST_WORD_KEY + 1.
	APPMESG_FIRST_WORD = 11
};

typedef uint8_t		ERROR_KEY_t;
typedef uint8_t		RESET_KEY_t;
typedef int16_t		TEXT_BLOCK_SIZE_KEY_t;
typedef int16_t		TOTAL_NUMBER_OF_BLOCKS_KEY_t;
typedef uint8_t		APPMESG_NUM_WORDS_KEY_t;
typedef uint16_t	APPMESG_WORD_START_INDEX_KEY_t;
typedef int16_t		APPMESG_BLOCK_NUMBER_KEY_t;
typedef uint32_t	APPMESG_FIRST_WORD_KEY_t;
typedef uint8_t		VERSION_MAJOR_KEY_t;
typedef uint8_t		VERSION_MINOR_KEY_t;
typedef uint8_t		VERSION_PATCH_KEY_t;
typedef uint32_t	APPMESG_FIRST_WORD_t;

/// Used for sending version numbers to and from the watch. Ex.: "1.0.31"
typedef struct {
	/// The major version number.
	unsigned char major;
	/// The minor version number.
	unsigned char minor;
	/// The patch version number.
	unsigned char patch;
} Version;

/// The Version that represents an unknown version number.
extern Version const stla_unknown_version_number;

/// Gets the current version of the Stela iOS app.
///
/// @return The current version of the Stela iOS app.
Version stla_get_iOS_Stela_version();

/// Compare two versions.
///
/// @param a The first version to compare.
/// @param b The second version to compare.
/// @return A positive value if @c a is greater than @c b, negative if @c a is less than @c b, or zero if @c a and @c b are equal.
NSInteger stla_version_compare(Version const a, Version const b);

/// Checks whether a version is equal to the unknown version number.
/// @remarks "@a Duuuuuuude. If the version number is, like, unknown, then how could we possibly know if our version is, like, the same, man?"
///
/// @param versionNumber The version number to check.
/// @return YES if the version is unknown, NO otherwise.
BOOL stla_version_is_unknown(Version const versionNumber);

/// Turns an NSString into a version number.
///
/// @param versionString The string form of the version number.
/// @return The Version form of the string, or 0.255.255 on error.
Version stla_string_to_version(NSString *versionString);

/// Turns a Version into a string.
///
/// @param versionNumber The version number to turn into an NSString.
/// @return The string form of the version.
NSString * stla_version_to_string(Version const versionNumber);

#endif
