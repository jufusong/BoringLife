find . ! -path "./.git/*" -type f \( -name "*.cc" -o -name "*.sample" -o -name "*.org" \) | while read LINE
do
    git add "${LINE}"
done
git commit -m 'update'
git push
