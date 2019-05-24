/*
Navicat MySQL Data Transfer

Source Server         : 1
Source Server Version : 50634
Source Host           : localhost:3306
Source Database       : blockchain

Target Server Type    : MYSQL
Target Server Version : 50634
File Encoding         : 65001

Date: 2019-05-24 20:41:07
*/

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for bit_block
-- ----------------------------
DROP TABLE IF EXISTS `bit_block`;
CREATE TABLE `bit_block` (
  `Height` int(11) NOT NULL,
  `nTx` int(11) DEFAULT NULL,
  `Size` int(11) DEFAULT NULL,
  `Nextblockhash` char(64) DEFAULT NULL,
  `Time` datetime DEFAULT NULL,
  `Nonce` bigint(20) DEFAULT NULL,
  `Difficulty` double DEFAULT NULL,
  `Bits` char(64) DEFAULT NULL,
  `Version` int(11) DEFAULT NULL,
  `Merkleroot` char(64) DEFAULT NULL,
  `blockhash` char(64) NOT NULL,
  `Confirmations` int(11) DEFAULT NULL,
  `Chainwork` char(64) DEFAULT NULL,
  `Previousblockhash` char(64) DEFAULT NULL,
  `Mediantime` datetime DEFAULT NULL,
  `Strippedsize` int(11) DEFAULT NULL,
  `Weight` int(11) DEFAULT NULL,
  KEY `Height` (`Height`) USING BTREE,
  KEY `blockhash` (`blockhash`) USING BTREE
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

-- ----------------------------
-- Table structure for bit_trans
-- ----------------------------
DROP TABLE IF EXISTS `bit_trans`;
CREATE TABLE `bit_trans` (
  `Blockhash` char(64) DEFAULT NULL,
  `TxHash` char(64) CHARACTER SET keybcs2 DEFAULT NULL,
  `Version` int(11) DEFAULT NULL,
  `InputCount` int(11) DEFAULT NULL,
  `OutputCount` int(11) DEFAULT NULL,
  `Size` int(11) DEFAULT NULL,
  `Locktime` int(11) DEFAULT NULL,
  `Vsize` int(11) DEFAULT NULL,
  `Weight` int(11) DEFAULT NULL,
  KEY `Blockhash` (`Blockhash`) USING BTREE,
  KEY `TxHash` (`TxHash`) USING BTREE
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

-- ----------------------------
-- Table structure for bit_txinput
-- ----------------------------
DROP TABLE IF EXISTS `bit_txinput`;
CREATE TABLE `bit_txinput` (
  `Txhash` char(64) DEFAULT NULL,
  `Sequence` bigint(20) DEFAULT NULL,
  `PreTxhash` char(64) DEFAULT NULL,
  `PaymentScript` varchar(8000) DEFAULT NULL,
  `Coinbase` varchar(255) DEFAULT NULL,
  `Blockhash` char(64) DEFAULT NULL,
  `PreTxid` int(11) DEFAULT NULL,
  KEY `Txhash` (`Txhash`) USING BTREE
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

-- ----------------------------
-- Table structure for bit_txoutput
-- ----------------------------
DROP TABLE IF EXISTS `bit_txoutput`;
CREATE TABLE `bit_txoutput` (
  `TxId` int(11) DEFAULT NULL,
  `Txhash` char(64) DEFAULT NULL,
  `Value` double(20,5) DEFAULT NULL,
  `ScriptPubKey` varchar(8000) DEFAULT NULL,
  `Address` char(64) DEFAULT NULL,
  `Type` char(64) DEFAULT NULL,
  KEY `Txhash` (`Txhash`) USING BTREE
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

-- ----------------------------
-- Table structure for eth_block
-- ----------------------------
DROP TABLE IF EXISTS `eth_block`;
CREATE TABLE `eth_block` (
  `Blockhash` varchar(255) NOT NULL,
  `ParentHash` varchar(255) DEFAULT NULL,
  `Coinbase` varchar(255) DEFAULT NULL,
  `StateRoot` varchar(255) DEFAULT NULL,
  `TxHash` varchar(255) DEFAULT NULL,
  `ReceiptHash` varchar(255) DEFAULT NULL,
  `Bloom` varchar(8000) DEFAULT NULL,
  `Difficulty` int(11) DEFAULT NULL,
  `Number` int(11) NOT NULL,
  `GasLimit` int(255) DEFAULT NULL,
  `GasUsed` int(255) DEFAULT NULL,
  `Time` datetime DEFAULT NULL,
  `Extra` varchar(8000) DEFAULT NULL,
  `MixDigest` varchar(255) DEFAULT NULL,
  `Nonce` varchar(255) DEFAULT NULL,
  `UncleHash` varchar(255) DEFAULT NULL,
  KEY `Blockhash` (`Blockhash`) USING BTREE,
  KEY `Number` (`Number`) USING BTREE
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

-- ----------------------------
-- Table structure for eth_trans
-- ----------------------------
DROP TABLE IF EXISTS `eth_trans`;
CREATE TABLE `eth_trans` (
  `AccountNonce` int(11) DEFAULT NULL,
  `GasPrice` int(11) DEFAULT NULL,
  `Gas` int(11) DEFAULT NULL,
  `Recipient` varchar(255) DEFAULT NULL,
  `Value` int(11) DEFAULT NULL,
  `Payload` mediumtext,
  `V` varchar(255) DEFAULT NULL,
  `R` varchar(255) DEFAULT NULL,
  `S` varchar(255) DEFAULT NULL,
  `Blockhash` varchar(255) NOT NULL,
  `Txhash` varchar(255) NOT NULL,
  `Sender` varchar(255) DEFAULT NULL,
  `Txid` int(11) DEFAULT NULL,
  KEY `Blockhash` (`Blockhash`) USING BTREE,
  KEY `Txhash` (`Txhash`) USING BTREE
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
