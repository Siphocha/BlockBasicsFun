// File: multi_transfer.js 
const { Web3 } = require('web3'); 
const web3 = new Web3('http://127.0.0.1:8545'); 
async function multipleTransfers() { 
 console.log('\n=== MULTIPLE TRANSACTIONS ===\n');   const accounts = await web3.eth.getAccounts(); 
 const transactions = [ 
 { from: accounts[0], to: accounts[1], amount: '2' },  { from: accounts[1], to: accounts[2], amount: '1' },  { from: accounts[2], to: accounts[3], amount: '0.5' },  { from: accounts[0], to: accounts[3], amount: '3' },  ]; 
  let totalGasUsed = BigInt(0); 
  for (let i = 0; i < transactions.length; i++) { 
 const txData = transactions[i]; 
 console.log(`Transaction ${i + 1}: ${txData.amount} ETH`);  console.log(` From: ${txData.from}`); 
 console.log(` To: ${txData.to}`); 
  const tx = await web3.eth.sendTransaction({ 
 from: txData.from, 
 to: txData.to, 
 value: web3.utils.toWei(txData.amount, 'ether'),  gas: 21000 
 }); 
  console.log(` Hash: ${tx.transactionHash}`);  console.log(` Gas: ${tx.gasUsed}\n`); 
  totalGasUsed += BigInt(tx.gasUsed); 
 } 
  console.log(`Total Gas Used: ${totalGasUsed}`); 
 console.log(`Total Transactions: ${transactions.length}`);   // Get final block number 
 const blockNumber = await web3.eth.getBlockNumber();  console.log(`Current Block: ${blockNumber}`); 
} 
multipleTransfers() 
 .then(() => process.exit(0)) 
 .catch(error => { 
 console.error('Error:', error); 
 process.exit(1); 
 }); 
