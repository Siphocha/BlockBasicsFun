// File: simple_transfer.js 
const { Web3 } = require('web3'); 
const web3 = new Web3('http://127.0.0.1:8545'); 
async function simpleTransfer() { 
 console.log('\n=== SIMPLE ETH TRANSFER ===\n'); 
  const accounts = await web3.eth.getAccounts(); 
 const sender = accounts[0]; 
 const receiver = accounts[1]; 
  // Check initial balances 
 const senderBalanceBefore = await web3.eth.getBalance(sender); 
 const receiverBalanceBefore = await web3.eth.getBalance(receiver);   console.log('BEFORE TRANSACTION:'); 
 console.log(`Sender: ${web3.utils.fromWei(senderBalanceBefore, 'ether')} ETH`);  console.log(`Receiver: ${web3.utils.fromWei(receiverBalanceBefore, 'ether')} ETH\n`);   // Send 5 ETH 
 console.log('Sending 5 ETH...'); 
 const tx = await web3.eth.sendTransaction({ 
 from: sender, 
 to: receiver, 
 value: web3.utils.toWei('5', 'ether'), 
 gas: 21000 
 }); 
  console.log(`Transaction Hash: ${tx.transactionHash}`); 
 console.log(`Gas Used: ${tx.gasUsed}\n`); 
  // Check final balances 
 const senderBalanceAfter = await web3.eth.getBalance(sender); 
 const receiverBalanceAfter = await web3.eth.getBalance(receiver); 
  console.log('AFTER TRANSACTION:'); 
 console.log(`Sender: ${web3.utils.fromWei(senderBalanceAfter, 'ether')} ETH`);  console.log(`Receiver: ${web3.utils.fromWei(receiverBalanceAfter, 'ether')} ETH\n`);   // Calculate gas cost 
 const gasCost = BigInt(tx.gasUsed) * BigInt(tx.effectiveGasPrice);  console.log(`Gas Cost: ${web3.utils.fromWei(gasCost.toString(), 'ether')} ETH`); } 
simpleTransfer() 
 .then(() => process.exit(0)) 
 .catch(error => { 
 console.error('Error:', error); 
 process.exit(1); 
 }); 
